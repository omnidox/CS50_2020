str = 'CarBadoordoordoordoordoordoordoordoordoordoordoordoordoorBoxNumKeydoordoordoordoorValRayCppSanNumKeydoordoordoordoorValRayCppSanNumKeydoordoordoordoorValRayCppSanNumKeydoordoordoordoorValRayCppSanNumKeydoordoordoordoorValRayCppSanNumKeydoordoordoordoorValRayCppSanNumKeydoordoordoordoorValRayCppSan'

n = 4
counter = 0
max_counter = 0
chunks = [str[i:i+n] for i in range(0, len(str), 1)]

for i in range (0, len(chunks),1):
    if chunks[i] == "door" and counter == 0:
        counter += 1
        
    if chunks[i] == "door" and chunks[i - n] == "door":
        counter += 1
        
    if chunks[i] == "door" and chunks[i + n] != "door": 
        if counter > max_counter :
            max_counter = counter
        counter = 0
        
        
# if chunks == "door" and str[(i + (n)):i+2*n] == "door":
    
#     counter += 1
print (counter)

print (max_counter)
        
# print(type(chunks))

# print (chunks)