# Audio Transcription Service

This repository contains the code for an audio transcription service using Flask and the `speech_recognition` library. The service accepts audio files, transcribes the speech to text, and returns the transcription as a JSON response.
## Supported Boards
- ESP32 S3 (Successfully Tested)
-ESP32 DOIT Devkit V1 (Under Test)

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

## Installation
  **Install server dependencies:**
    1. open CMD
    2. pip install Flask SpeechRecognition

## Usage

1. **Run the Flask server:**

    ```sh
    python app.py
    ```

2. **Upload audio files:**

    - Use a tool like Postman or curl to send a POST request to `http://localhost:8888/uploadAudio` with the audio file in the body.

    Example using `curl`:

    ```sh
    curl -X POST -H "Content-Type: audio/wav" --data-binary @your-audio-file.wav http://localhost:8888/uploadAudio
    ```

    Replace `your-audio-file.wav` with the path to your audio file.

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
