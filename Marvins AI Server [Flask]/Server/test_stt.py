import requests

# URL of the Flask app endpoint
url = 'http://192.168.0.100:8888/uploadAudio'

# Path to the audio file to be uploaded
audio_file_path = 'hello.wav'

# Read the audio file
with open(audio_file_path, 'rb') as audio_file:
    audio_data = audio_file.read()

# Send POST request with the audio data
response = requests.post(url, data=audio_data)

# Print the response from the server
print('Response status code:', response.status_code)
print('Response content:', response.json() if response.headers.get('Content-Type') == 'application/json' else response.text)
