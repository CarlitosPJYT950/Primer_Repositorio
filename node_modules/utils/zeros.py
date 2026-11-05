import os, zipfile

with open("zeros.bin", "wb") as f:
    # TODO: write code...
    f.write(bytes(100_000))
    
with zipfile.ZipFile("zeros.zip", "w", zipfile.ZIP_DEFLATED) as z:
    # TODO: write code...
    z.write("zeros.bin")

print(os.path.getsize("zeros.bin"))
print(os.path.getsize("zeros.zip"))