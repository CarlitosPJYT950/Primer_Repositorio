import os, zipfile

with open("zeros.bin", "wb") as f:
    # TODO: Write 100MB of zeros to the file
    f.write(bytes(100_000))  # Write 1KB of zeros to the file

with zipfile.ZipFile("zeros.zip", "w", zipfile.ZIP_DEFLATED) as z:
    # TODO: Add the zeros.bin file to the zip archive
    z.write("zeros.bin")  # Add the zeros.bin file to the zip archive

print(os.path.getsize("zeros.bin"))  # Print the absolute path of the created bin file
print(os.path.getsize("zeros.zip"))  # Print the absolute path of the created zip file