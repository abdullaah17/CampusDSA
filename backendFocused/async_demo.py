import asyncio

async def task(name, time):
    print(f"{name} started")
    await asyncio.sleep(time)
    print(f"{name} finished")

async def main():
    await asyncio.gather(
        task("Task 1", 2), #2nd
        task("Task 2", 3), #3rd
        task("Task 3", 1)  #1st
    )

asyncio.run(main())
# What async is GOOD for:
# API calls
# Database queries
# WebSockets
# Background tasks
# FastAPI endpoints

# What async is BAD for:
# Heavy CPU work
# Image processing
# ML training

# For that:
# Threads
# Processes
# Celery workers