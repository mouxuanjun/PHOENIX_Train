# 1.FreeRTOS
## 1. 项目介绍
- 在/UserLib下封装LED类，实现了自定义周期的呼吸灯闪烁方法
- 建立三个FreeRTOS Task，分别控制C板上了的3色LED灯，不同周期组合的三色呼吸灯可以实现随机颜色组合等功能
## 2. 项目架构
project_root/
├── Core/
├── Drivers/
├── Middlewares/
├── UserTasks/
│   └── Src/
│       ├── LED_B.c
│       ├── LED_G.c
│       └── LED_R.c
|   └── Inc/
├── UserLib/
|   └── Src/
|        └── LED.c
|        └── Src/
|        └── LED.c
