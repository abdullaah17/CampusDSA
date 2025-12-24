from fastapi import FastAPI #Python framework for building backend APIs.
import asyncio

app = FastAPI()

@app.get("/data")
async def get_data():
    await asyncio.sleep(2)
    return {"status": "ok"}
