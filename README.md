# Reverse digits

> reverses Digits in number

**Date:** 17/10/2026
**Tags:** modulo, fgets,

## 🎯 Goal

What I wanted to learn: 
- practice fgets int checks some more
- find differents ways to split int by digits

## 💡 What I Learned

- learned the difference between sizeof(arr) and sizeof(arr)/ sizeof(arr[0]), the first is used to determine the number of bytes in arr, second is used when you want to know the number of elements in arr

## 🐛 Mistakes & Fixes

- **Problem:** first i used buf[2] but that would not read the input correctly because fgets reads count-1 and adds '\0' so buf would at most contain 1 char + '\0', buf[3] would contain 2 chars + '\0' but would not contain the '\n' needed for the strchr check to see if input was fully converted.
  **Fix:** buf[number_of_digits_to_reverse + 2] 

## ❓ Open Questions

- 
