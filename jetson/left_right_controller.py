from controller import Controller

class LeftRightController(Controller):

    def __init__(self, reference, min_threshold=5, max_threshold=10):
        self.reference = reference
        self.min_threshold = min_threshold
        self.max_threshold = max_threshold


    def control(self, point):
        error = self.reference - point

        right_command = p*error
        left_command = -1*p*error

        if abs(left_command) < self.min_threshold:
            left_command = 0
        elif abs(left_command) > self.max_threshold:
            left_command = self.max_threshold

        if abs(right_command) < self.min_threshold:
            right_command = 0
        elif abs(right_command) > self.max_threshold:
            right_command = self.max_threshold

        return left_command, right_command

