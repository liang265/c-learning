# pwn-lab
五个从易到难的栈溢出靶题，附完整 exp 与 writeup。
## 环境要求
- Ubuntu 24.04 / WSL2
- gcc
- gdb
- python3
## 目录结构
```
pwn-lab/
├── chals/          题目源码，每题一个目录
├── solves/         对应的 exp 脚本
└── writeups/       对应的解题报告
```
## 题目列表
| 编号 | 名字 | 考点 | 状态 | 
|---|---|---|---|
| 01 | ret2win | 覆盖返回地址 | 已交付 |
| 02 | stack-align | ret gadget 对齐 | 未交付 |
## 怎么构建一题
```
cd chals/01-ret2win
gcc -Wall -g -fno-stack-protector -no-pie -o chal chal.c
```
## 怎么跑一题
```
cd solves
python3 01.py
```
## 免责声明
本项目所有题目均由作者自行编写，仅用于个人学习与 CTF 训练。未经授权对他人系统进行测试属于违法行为。
