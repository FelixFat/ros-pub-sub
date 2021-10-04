import rospy
from std_msgs.msg import String

def callback(data):
    rospy.loginfo('I heard: %s', data.data)

if __name__ == '__main__':
    rospy.init_node('sub_listener', anonymous = True)
    rospy.Subscriber('chatter', String, callback)
    
    rospy.spin()
