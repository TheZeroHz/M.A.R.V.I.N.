struct Device {
  String dev_name;
  String kernel_name;
};

struct Keywords {
  String cmd_name;
  String state;
};

struct LocalKeywords {
  String cmd_name;
  String cmd_kernel;
};

Device device[] = {
  {"fan ", "fan1"},
  {"room light ", "led1"},
  {"kitchen light ", "led2"},
  {"window ", "window1"},
};

Keywords keys[] = {
  {"turn ", ""},
  {"close ", "close"},
  {"open ", "open"},
};

LocalKeywords localKeys[] = {
  {"come here ","come_here"},
  {"move forward ","move_forward"},
  {"turn left ","turn_left"},
  {"turn right ","turn_right"},
  {"dance ","dance"},
  {"go backward ","go_backward"},
  {"hands up ","hands_up"},
  {"jump ","jump"},
};

String cloud_cmd = "";  // To store all sub_cloud values
String local_cmd = "";  // To store local command values

String addCommasToCommand(String command) {
  String result = command;
  for (int i = 0; i < sizeof(keys) / sizeof(Keywords); i++) {
    String cmd_name = keys[i].cmd_name;
    int pos = result.indexOf(cmd_name);
    while (pos != -1) {
      if (pos > 0 && result[pos - 1] != ',') {
        result = result.substring(0, pos) + "," + result.substring(pos);
        pos++;
      }
      pos = result.indexOf(cmd_name, pos + cmd_name.length() + 1);
    }
  }
  return result;
}

void extractLocalCommand(String originalSubCommand) {
  for (int i = 0; i < sizeof(localKeys) / sizeof(LocalKeywords); i++) {
    if (originalSubCommand.indexOf(localKeys[i].cmd_name) != -1) {
      local_cmd += localKeys[i].cmd_kernel + "~";
    }
  }
}

void executeCommand(String subCommand) {
  String originalSubCommand = subCommand;  // Store original subCommand for local_cmd extraction

  // Extract local commands from the unmodified originalSubCommand before trimming
  extractLocalCommand(originalSubCommand);

  subCommand.trim();
  String cmd_name = "";
  String state = "";

  // Check for cloud-related commands
  for (int i = 0; i < sizeof(keys) / sizeof(Keywords); i++) {
    int cmdPos = subCommand.indexOf(keys[i].cmd_name);
    if (cmdPos != -1) {
      cmd_name = keys[i].cmd_name;

      if (cmd_name == "turn") {
        if (subCommand.indexOf("on") != -1) {
          state = "on";
        } else if (subCommand.indexOf("off") != -1) {
          state = "off";
        }
      } else {
        state = keys[i].state;
      }

      subCommand = subCommand.substring(cmdPos + cmd_name.length());
      subCommand.trim();
      break;
    }
  }

  // Process cloud commands
  if (cmd_name != "" && state != "") {
    for (int j = 0; j < sizeof(device) / sizeof(Device); j++) {
      if (subCommand.indexOf(device[j].dev_name) != -1) {
        String sub_cloud = device[j].kernel_name + state;
        cloud_cmd += sub_cloud + "~";  // Accumulate sub_cloud into cloud_cmd
      }
    }
  }
}

void processCommand(String command) {
  while (command.length() > 0) {
    int cmdIndex = command.indexOf(',');
    String subCommand;

    if (cmdIndex == -1) {
      subCommand = command;
      command = "";
    } else {
      subCommand = command.substring(0, cmdIndex);
      command = command.substring(cmdIndex + 1);
    }

    subCommand.trim();
    executeCommand(subCommand);
  }
}

void setup() {
  Serial.begin(115200);
}

void loop() {
  String command;
  if (Serial.available() > 0) {
    command = Serial.readString();
    Serial.println("Your CMD: => " + command);

    command = addCommasToCommand(command);  // Add commas between different commands
    processCommand(command);  // Process both cloud and local commands

    Serial.println("Final cloud_cmd: " + cloud_cmd);
    Serial.println("Final local_cmd: " + local_cmd);

    // Reset commands for next input
    cloud_cmd = "";
    local_cmd = "";
  }
}
//turn on room light , turn off fan and come here
