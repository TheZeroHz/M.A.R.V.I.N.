# Audio Transcription Service

This repository contains the code for an audio transcription service using Flask and the `speech_recognition` library. The service accepts audio files, transcribes the speech to text, and returns the transcription as a JSON response.
## Supported Boards
- ESP32 S3 (Successfully Tested)
- ESP32 DOIT Devkit V1 (Under Test)

## Features
- Upload audio files for transcription.
- Uses `speech_recognition` library for speech-to-text conversion.
- Simple Flask web server to handle file uploads and return transcriptions.

## Before you begin, ensure you have met the following requirements:
### Server Requirements:
- Python 3.7 or later installed.
- `pip` package installer.
- Internet connection for installing dependencies.
### ESP32 Requirements
- ESP Version 2.0.14
- Arduino IDE 2.3.2
- I2S MIC (INMP-331)

## Install server dependencies   
- download and install python if not installed from [here](https://www.python.org/downloads/)
- open CMD on windows [if you are using linux please search google command for the following]
- ```sh
    pip3 install flask
    ```
- ```sh
    pip3 install SpeechRecognition pydub
    ```

## Run Server

1. **Download stt_api.py and see the directory of the downloaded file**
![Step 1](img/S1.PNG)

2. **Open CMD Then Goto that folder and Run command**
 ```sh
    python stt_api.py
    ```
![Step 2](img/S2.PNG)
3. **Receive the transcription:**

    The server will respond with a JSON object containing the transcription.

## Example

![Example Usage](example.png)

## Project Structure

```plaintext
.
├── app.py               # Main server code
├── requirements.txt     # List of dependencies
├── README.md            # This file
└── example.png          # Example image for usage
