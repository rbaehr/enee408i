from controller import Controller

class ForwardBackController(Controller):

    def __init__(self, center_x, min_threshold=5, max_threshold=10):
        self.center_x = center_x
        self.min_threshold = min_threshold
        self.max_threshold = max_threshold


    def control(self, radius):
        error = self.reference - radius

        right_command = p*error
        left_command = p*error

        if abs(left_command) < self.min_threshold:
            left_command = 0
        elif abs(left_command) > self.max_threshold:
            left_command = self.max_threshold

        if abs(right_command) < self.min_threshold:
            right_command = 0
        elif abs(right_command) > self.max_threshold:
            right_command = self.max_threshold

        return left_command, right_command

