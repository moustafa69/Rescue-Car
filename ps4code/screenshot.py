from pyautogui import screenshot
from time import sleep

interval  = 5
mission_time = 60

mission_shots = mission_time // interval

for i in range(mission_shots):
    
    screenshot(f"missionShots/missionShot {i+1}.png")
    print("taking screenshot...")
    print(f"Screenshot {i} taken")
    sleep(interval)
    print(f"{(i+1)*5} seconds have passed")
print("Mission Complete!")
