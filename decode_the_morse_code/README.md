# Decode The Morse Code 

In this kata you have to write a simple Morse code decoder. While the Morse code is now mostly superseded by voice and digital data communication channels, it still has its use in some applications around the world.     
The Morse code encodes every character as a sequence of "dots" and "dashes".    

***Bellow you can check the International Morse Code:***   
<img src="https://user-images.githubusercontent.com/5942022/143738733-a1fa7516-4e9c-4530-9c10-0cef97c70caf.jpg" width="400px">    
   
`The Morse code is case-insensitive`, traditionally capital letters are used.    
When the message is written in Morse code:   
- `a single space` is used to separate the character codes,   
- `3 spaces` are used to separate words.

```
NOTE: Extra spaces before or after the code have no meaning and should be ignored.
```   

In addition to letters, digits and some punctuation, there are some special service codes. These special codes are treated as single special characters, and usually are transmitted as separate words.    
<br>
The most notorious of those is the international `distress signal SOS` coded as `···−−−···`. 

Your task is to implement a function that would take the morse code as input and return a decoded human-readable string.

## For example:
```cpp   
decodeMorse('.... . -.--   .--- ..- -.. .')
// should return "HEY JUDE"
```   
