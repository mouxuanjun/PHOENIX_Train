# 开发日志
___
## 04/22
### 1.进度状况
1. 完成PID库的封装，没有验证
### 2.明日TODO
 - [x] 验证PID库
 - [x] 封装GM6020的PID库
___
## 04/23
### 1.进度状况
1. 完成GM6020速度环pid封装，但是没有完全弄懂库的运作原理
2. 不要在main.c里面写cpp_main
### 2.明日TODO
- [x] GM6020速度环参数整定
- [x] 整定GM6020的位置环
- [x] 融入前馈参数
___
## 04/24
### 1.进度状况
1. 完成GM6020速度环pid封装,前馈参数未完全整定
2. PID参数基于采样周期的参数同步
### 2.明日TODO
- [ ] CPP菜鸟教程
- [ ] 4310电机封装
___
## 04/25
### 1.进度状况
1. **一定要给前馈上过圈保护！**
``` cpp
    /* 判断是否需要前馈过圈保护 */
    float temp_Pre_target = PID_Info.Pre_Target;
    float temp_Target = PID_Info.Target;
    switch (PID_Type) {
    case speed: break;
    case GM6020_angle: {
        //过圈保护
        if (temp_Target - temp_Pre_target > 4096) {
            temp_Pre_target += 8192;
        }
        else if (temp_Target - temp_Pre_target < -4096) {
            temp_Target += 8192;
        }
        break;
    }
    }
    f_out = (temp_Target - temp_Pre_target) * PID_Params.K_F;
    PID_Info.F_Out = f_out;
```

2. 
