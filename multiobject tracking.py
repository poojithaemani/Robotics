import cv2
import numpy as np 
TrDict={'csrt': cv2.TrackerCSRT_create}
trackers = cv2.MultiTrackerCSRT_create()
v=cv2.VideoCapture(0)
ret,frame = v.read()
k=2
for i in range(k):
    cv2.imshow('Frame',frame) 
    bbi = cv2.selectROI('Frame',frame) 
    tracker_i = TrDict['csrt']()    
    trackers.add(tracker_i,frame,bbi)
while True:
    ret,frame = v.read()
    if not ret:
        break
    (success,boxes) = trackers.update(frame)
    for box in boxes:
        (x,y,w,h) = [int(a) for a in box]
        cv2.rectangle(frame,(x,y),(x+w,y+h),(100,200,200),2)
    cv2.imshow('Frame',frame)
    key = cv2.waitKey(5) & 0xFF
    if key == ord('q'):
        break
v.release()
cv2.destroyAllWindows()

