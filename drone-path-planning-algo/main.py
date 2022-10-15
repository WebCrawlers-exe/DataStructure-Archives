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
    if p1[0]-p2[0]==0:
        m=9999
    else:
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

# Obstacles
obs=[[random.randint(100,700),random.randint(100,600),random.randint(50,100)]]
# obs=[[350, 350, 50], [500, 400, 75], [150, 150, 60], [700, 650, 60], [150, 1, 60], [10, 300, 60], [-150, -150, 60], [1050, 950, 60]]
# obs=[[691, 324, 90], [215, 214, 31], [474, 529, 73], [262, 368, 67], [303, 482, 32], [139, 516, 59]]
# We get random points for circle and if the random circle doesnt overlap with other 
# circles we move forward
for i in range(9):
    t=True
    while t:
        x=random.randint(100,700)
        y=random.randint(100,600)
        r=random.randint(50,100)
        for j in obs:
            if circleOverlapping(j,[x,y,r]):
                t=True
                break
            else:
                t=False
    obs.append([x,y,r])

def changeObs():
    lis1=[-10, 10, 0]
    limitflag=False
    for i in obs:
        temp1=random.choice(lis1)
        temp2=random.choice(lis1)
        for j in obs:
            if j!=i:
                if circleOverlapping(j, [i[0]+temp1,i[1]+temp2,i[2]]) or ((i[0]+temp1-i[2]<0 or i[0]+temp1+i[2]>800) or (i[1]+temp2-i[2]<0 or i[1]+temp2+i[2]>700)) :
                    limitflag=True
                    break
        if limitflag==False:
            i[0]+=temp1
            i[1]+=temp2


# Waypoints
while True:
    wayPoints=[[5,5,'s'],[790,690,'f']]
    visited=[wayPoints[0]]
    bObs=[]
    curPt=wayPoints[0]
    nextPt=wayPoints[1]
    endPt=wayPoints[-1]
    changeObs()

    counter=0
    print(wayPoints)
    while True:
        print(counter)
        counter+=1
        clean(wayPoints)
        print("cur:",curPt,"next:",nextPt)
        if curPt[2]=='c':
            curPt=nextPt
            nextPt=wayPoints[wayPoints.index(nextPt)+1]
        else:
            bObs=[]
            l=eqOfLine(curPt,nextPt)
            for i in obs:
                p=footOfPerpendicular(l,i[0:2])
                if lineInCircle(l,i,p):
                    if intOrExtDiv(curPt,nextPt,p)=="internal" and round(p[0],3)!=round(nextPt[0],3) and round(p[1],3)!=round(nextPt[1],3):
                        bObs.append([i[0],i[1],i[2],distance(i[0:2],curPt)])
            if len(bObs)>0:
                bObs.sort(key=lambda x:x[-1])
                closestObs=bObs[0]
                print("close:",closestObs)
                print("bobs:",bObs)
                tangentPoint1,tangentPoint2=getTangentPoints(curPt,closestObs)
                l1=eqOfLine(curPt,tangentPoint1)
                l2=eqOfLine(curPt,tangentPoint2)

                if angle(l1[0],l[0])<=angle(l2[0],l[0]):
                    newNextPt=tangentPoint1
                else:
                    newNextPt=tangentPoint2
                newNextPt.append('c')
                a,b=getTangentPoints(nextPt,closestObs)

                if distance(a,newNextPt)>=distance(b,newNextPt):
                    newArcPoint=b
                else:
                    newArcPoint=a
                newArcPoint.append('l')
                ind=wayPoints.index(curPt)
                wayPoints.insert(ind+1,newNextPt)
                wayPoints.insert(ind+2,newArcPoint)
                nextPt=newNextPt
            else:
                curPt=nextPt
                if curPt==wayPoints[-1]:
                    break
                nextPt=wayPoints[wayPoints.index(nextPt)+1]
        print("WP:",wayPoints)

                    

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

    tpp1=None
    tpp2=None

    screen.fill(white)
    for event in pygame.event.get():
        # Allowing program to quit
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    
    # drawing the obstacles
    for i in obs:
        pygame.draw.circle(screen,green,i[0:2],i[2])
        pygame.draw.circle(screen,blue,i[0:2],i[2]-5)
    for i in range(len(wayPoints)):
        pygame.draw.circle(screen,blue,wayPoints[i][0:2],2)
        if wayPoints[i][-1]=='l' or wayPoints[i][-1]=='s':
            pygame.draw.line(screen,black,wayPoints[i][0:2],wayPoints[i+1][0:2])
    pygame.display.update()
    clock.tick(2)