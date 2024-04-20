# uvicorn main:app --reload --host 0.0.0.0 --port 8000
from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
import random

app = FastAPI()

# Set up CORS
origins = [
    "http://localhost:8000",  # Allow localhost for development
    "http://localhost:8080",  # Also allow localhost with a different port
    "http://localhost:3000",  # Also allow localhost with a different port
    "http://localhost:5000",  # Also allow localhost with a different port
]

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

@app.get("/ECG")
def read_random():
    return {"data": random.randint(1, 100)}
