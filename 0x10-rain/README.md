# Rainwater Trapping
```
Given a list of non-negative integers representing the heights of walls with unit width 1, as if viewing the cross-section of a relief map, this Python function calculates how many square units of water will be retained after it rains.
```
## Prototype
```
def rain(wallls):
```

* walls is a list of non-negative integers.
* Returns an integer indicating the total amount of rainwater retained.
* Assumes that the ends of the list (before index 0 and after index walls[-1]) are not walls, meaning they will not retain water.
* If the list is empty, it returns 0.

## How it Works
```
walls is a list of non-negative integers.
Returns an integer indicating the total amount of rainwater retained.
Assumes that the ends of the list (before index 0 and after index walls[-1]) are not walls, meaning they will not retain water.
If the list is empty, it returns 0.
```