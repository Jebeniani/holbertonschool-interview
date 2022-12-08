#!/usr/bin/python3
def canUnlockAll(boxes):
    if boxes is None or len(boxes) == 0:
        return False
    key = [0]
    for k in key:
        for b in boxes[k]:
            if b not in key and b < len(boxes):
                key.append(b)
    if len(key) == len(boxes):
        return True
    return False