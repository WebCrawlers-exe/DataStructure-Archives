import pygame,sys,random,math

# Find distance between 2 points
def distance(p1,p2):
    return ((p1[0]-p2[0])**2+(p1[1]-p2[1])**2)**.5

# To see if 2 circles overlap
def circleOverlapping(c1,c2):
    d=distance(c1[0:2],c2[0:2])
    if d-10>(c1[2]+c2[2]):
        return False
    else:
        return True

# takes 2 points
def eqOfLine(p1,p2):
    m=(p1[1]-p2[1])/(p1[0]-p2[0])
    return [m,-m*p1[0]+p1[1]]
# return a list of form y=l[0]x+l[1]  

def quadraticFormula(a,b,c):
    d=b**2-4*a*c
    if d>=0:
        return (-b+d**.5)/(2*a),(-b-d**.5)/(2*a)
    else:
        return "No Tangent"

def pointOnCircle(p,c):
    # print("POC:",p,distance(p,c[0:2]))
    if round(distance(p,c[0:2]))==c[2]:
        return True
    return False

def clean(l):
    i=0
    while i<len(l)-2:
        if l[i][0:2]==l[i+1][0:2]:
            l.pop(i)
        i+=1

# checks if line is in circle
def lineInCircle(l,c,p):
    if pointOnCircle(p,c):
        return False
    dist=(((l[0]*c[0]-c[1]+l[1])**2)/((l[0])**2+1))**.5
    if dist>=c[2]:
        return False
    # print("LIC:",dist,c[2])
    return True

# returns angle between 2 lines
# takes slope of both lines
def angle(m1,m2):
    rad=math.atan((((m1-m2)/(1+m1*m2))**2)**.5)
    return math.degrees(rad)

# takes point and circle returns angle fow which
# x=r*cos(angle) and y=r*sin(angle)
# point needs to be on circle
def parametricAngle(p,c):
    angle=(math.acos((p[0]-c[0])/c[-1]),math.asin((p[1]-c[1])/c[-1]))
    if angle[0]<=math.pi/2 and angle[1]>=0:
        return angle[0]
    elif angle[0]<=math.pi/2 and angle[1]<0:
        return 2*math.pi+angle[1]
    elif angle[0]>math.pi/2 and angle[1]>0:
        return angle[0]
    else:
        return math.pi+angle[1]

# find points of intersection between 2 circles
def getTangentPoints(p,c):
    # circle 1: (p[0], p[1]), radius r0
    # circle 2: (c[0], c[1]), radius c[2]

    # temp=distance()
    d=distance(p,c[0:2])
    r0=(abs(d**2-c[2]**2))**.5
    print(d,r0,c[2],c[3])
    # non intersecting
    if d > r0 + c[2] :
        return None
    # One circle within other
    if d < abs(r0-c[2]):
        return None
    # coincident circles
    if d == 0 and r0 == c[2]:
        return None
    else:
        a=(r0**2-c[2]**2+d**2)/(2*d)
        h=math.sqrt(r0**2-a**2)
        x2=p[0]+a*(c[0]-p[0])/d   
        y2=p[1]+a*(c[1]-p[1])/d   
        x3=x2+h*(c[1]-p[1])/d     
        y3=y2-h*(c[0]-p[0])/d 

        x4=x2-h*(c[1]-p[1])/d
        y4=y2+h*(c[0]-p[0])/d
        
        return [x3,y3],[x4,y4]

def getCircleIntersections(p,c):
    # temp=distance()
    d=distance(p,c[0:2])
    r0=p[-1]
    print(d,r0,c[2],c[3])
    # non intersecting
    if d > r0 + c[2] :
        return None
    # One circle within other
    if d < abs(r0-c[2]):
        return None
    # coincident circles
    if d == 0 and r0 == c[2]:
        return None
    else:
        a=(r0**2-c[2]**2+d**2)/(2*d)
        h=math.sqrt(r0**2-a**2)
        x2=p[0]+a*(c[0]-p[0])/d   
        y2=p[1]+a*(c[1]-p[1])/d   
        x3=x2+h*(c[1]-p[1])/d     
        y3=y2-h*(c[0]-p[0])/d 

        x4=x2-h*(c[1]-p[1])/d
        y4=y2+h*(c[0]-p[0])/d
        
        return [x3,y3],[x4,y4]

def intOrExtDiv(s,e,p):
    if round(distance(s,p)+distance(p,e),6)>round(distance(s,e),6):
        return "external"
    else:
        return "internal"

def footOfPerpendicular(l,p):
    temp=(l[0]*p[0]-p[1]+l[1])/(l[0]**2+1)
    y=p[1]+temp
    x=p[0]-(temp*l[0])
    return (x,y)

def genObs(count):
    obs=[]
    for i in range(count):
        flag=True
        while flag:
            x=random.randint(100,700)
            y=random.randint(100,600)
            r=random.randint(50,120)
            for j in waypoints:
                if circleOverlapping([j[0],j[1],10],[x,y,r]):
                    flag=True
                    break
                else:
                    flag=False
            if flag==False:
                for k in obs:
                    if circleOverlapping(k,[x,y,r]):
                        flag=True
                        break
                    else:
                        flag=False
        obs.append([x,y,r])
    return obs

waypoints=[[5,5,'s'],[100,200,'l'],[400,250,'l'],[500,425,'l'],[720,590,'l'],[790,690,'f']]


obs=genObs(10)
curPt=waypoints[0]
nextPt=waypoints[1]

while True:
    # break
    l=eqOfLine(curPt,nextPt)

    # Check for obstacles in the way
    bObs=[]
    for i in obs:
            p=footOfPerpendicular(l,i[0:2])
            if lineInCircle(l,i,p):
                if intOrExtDiv(curPt,nextPt,p)=="internal" and round(p[0],3)!=round(nextPt[0],3) and round(p[1],3)!=round(nextPt[1],3):
                    bObs.append([i[0],i[1],i[2],distance(i[0:2],curPt)])
        
    if len(bObs)>0:
        # We sort as per distance of obstacles
        bObs.sort(key=lambda x:x[-1])
        closestObs=bObs[0]
        
        # Getting the first point we have to go to one the circle
        tangentPoint1,tangentPoint2=getTangentPoints(curPt,closestObs)
        l1=eqOfLine(curPt,tangentPoint1)
        l2=eqOfLine(curPt,tangentPoint2)
        if angle(l1[0],l[0])<=angle(l2[0],l[0]):
            temp=[tangentPoint1]
        else:
            temp=[tangentPoint2]

        a,b=getTangentPoints(nextPt,closestObs)

        if distance(a,temp[0])>=distance(b,temp[0]):
            targetPoint=b
        else:
            targetPoint=a

        maxChordLength=2*(10*(2*closestObs[-1]-10))**0.5
        ctr2=0
        while True:
            tempL=eqOfLine(temp[ctr2],nextPt)
            tempFOP=footOfPerpendicular(tempL,closestObs[0:2])
            if distance(closestObs[0:2],tempFOP)>closestObs[-1]-10:
                break
            else:
                if distance(temp[ctr2],targetPoint)<=maxChordLength:
                    temp.append(targetPoint)
                    break
                else:
                    tempC=[temp[ctr2][0],temp[ctr2][1],maxChordLength]
                    a,b=getCircleIntersections(tempC,closestObs)
                    if distance(a,targetPoint)<=distance(b,targetPoint):
                        temp.append(a)
                    else:
                        temp.append(b)
                    ctr2+=1
        ind=waypoints.index(curPt)
        for j in range(len(temp)):
            waypoints.insert(ind+j+1,temp[j])
        curPt=waypoints[ind+j+1]
        nextPt=waypoints[ind+j+2]
    else:
        curPt=nextPt
        if curPt==waypoints[-1]:
            break
        nextPt=waypoints[waypoints.index(nextPt)+1]


# Intialize the pygame
pygame.init()
clock=pygame.time.Clock()

# create the screen
screen = pygame.display.set_mode((800, 700))

# colours
blue=(0,0,255)
green=(0,255,0)
red=(255,0,0)
black=(0,0,0)
white=(255,255,255)

while True:
    screen.fill(white)
    for event in pygame.event.get():
        # Allowing program to quit
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    
    # drawing the obstacles
    for i in obs:
        pygame.draw.circle(screen,green,i[0:2],i[2],2)
        pygame.draw.circle(screen,blue,i[0:2],i[2]-10)
        pygame.draw.circle(screen,red,i[0:2],i[2]-15)

    for i in range(len(waypoints)-1):
        pygame.draw.circle(screen,blue,waypoints[i][0:2],2)
        # if waypoints[i][-1]=='l' or waypoints[i][-1]=='s':
        pygame.draw.line(screen,black,waypoints[i][0:2],waypoints[i+1][0:2])
    pygame.draw.circle(screen,blue,waypoints[-1][0:2],2)
    
    pygame.display.update()
    clock.tick(3)