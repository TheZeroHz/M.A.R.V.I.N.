from flask import Flask, request, jsonify
import os
import time
from vosk import Model, KaldiRecognizer
import wave
import json
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'  # Suppress TensorFlow warnings
from transformers import pipeline

# Specify the model explicitly
get_sentiment = pipeline("sentiment-analysis", model="finiteautomata/bertweet-base-sentiment-analysis")

app = Flask(__name__)
file_name = 'recording.wav'
model = Model("stt_models\\vosk-model-en-us-0.22-lgraph")  # Path to the Vosk model directory

@app.route('/uploadAudio', methods=['POST'])
def upload_audio():
    if request.method == 'POST':
        try:
            t1 = time.time()
            # Save the uploaded file
            with open(file_name, 'wb') as f:
                f.write(request.data)
            
            # Transcribe the audio file
            transcription = speech_to_text(file_name)
            sentiment = get_sentiment(transcription)
            t2 = time.time()
            
            return jsonify({'transcription': transcription}, {'sentiment': sentiment}, {'cpu_time(ms)': (t2 - t1) * 1000}), 200
        except Exception as e:
            return str(e), 500
    else:
        return 'Method Not Allowed', 405

def speech_to_text(file_name):
    # Open the audio file
    wf = wave.open(file_name, "rb")
    
    if wf.getnchannels() != 1 or wf.getsampwidth() != 2 or wf.getcomptype() != "NONE":
        return "Audio file must be WAV format mono PCM."
    
    recognizer = KaldiRecognizer(model, wf.getframerate())
    
    transcription = ""
    while True:
        data = wf.readframes(4000)
        if len(data) == 0:
            break
        if recognizer.AcceptWaveform(data):
            result = recognizer.Result()
            result_dict = json.loads(result)
            transcription += result_dict.get('text', '') + ' '
    
    return transcription.strip()

if __name__ == '__main__':
    port = 8888
    app.run(host='0.0.0.0', port=port)
    print(f'Listening at {port}')
