def is_palindrom(word : str) -> bool:
  if len(word) <= 1:
    return True
  
  if word[0] == word[-1]:
    return is_palindrom(word[1:len(word) - 1])
  else:
    return False

def palindrom_bf(word : str) -> tuple:
  for start in range(0, len(word)):
    if is_palindrom(word[start:len(word)]):
      append = word[0:start]
      ret = word + append[::-1]
      return ret 

word = str(input())
print(len(palindrom_bf(word)))