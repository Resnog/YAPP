import pybullet as p
import time
import pybullet_data

class SimEnv:

    def __init__(self, physicsClient=p.GUI):
        self.physicsClient = p.connect(physicsClient)
        p.setAdditionalSearchPath(pybullet_data.getDataPath())
        self.elements = [p.loadURDF('plane.urdf')]

    def run(self, timelen=10000):
        for i in range(timelen):
            p.stepSimulation()
            time.sleep(1./240.)

env = SimEnv()        
        
p.setGravity(0,0,-10)
planeId = p.loadURDF('plane.urdf')
cubeStartPos = [0,0,1]
cubeStartOrientation = p.getQuaternionFromEuler([0,0,0])
boxId = p.loadURDF('r2d2.urdf', cubeStartPos, cubeStartOrientation)

cubePos, cubeOrn = p.getBasePositionAndOrientation(boxId)
print(cubePos, cubeOrn)
p.disconnect()