import os
import time
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'  # Suppress TensorFlow warnings

from transformers import pipeline

# Specify the model explicitly
senti_pipeline = pipeline("sentiment-analysis",model="finiteautomata/bertweet-base-sentiment-analysis")

# Use the pipeline
t1=time.time()
result = senti_pipeline("I will never kill you.Always love you.")
t2=time.time()
print((t2-t1)*1000)
print(result)

t1=time.time()
result = senti_pipeline("I will kill you.Never love you.")
t2=time.time()
print((t2-t1)*1000)
print(result)


t1=time.time()
result = senti_pipeline("Who is seikh hasina")
t2=time.time()
print((t2-t1)*1000)
print(result)


t1=time.time()
result = senti_pipeline("goto hell man")
t2=time.time()
print((t2-t1)*1000)
print(result)
