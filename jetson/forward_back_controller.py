from controller import Controller

class ForwardBackController(Controller):

    def __init__(self, reference, p, min_threshold=-25, max_threshold=25):
        self.reference = reference
	self.p = p
        self.min_threshold = min_threshold
        self.max_threshold = max_threshold


    def control(self, radius):
        error = self.reference - radius

        right_command = self.p*error
        left_command = self.p*error

        if left_command < self.min_threshold:
            left_command = 0
        elif left_command > self.max_threshold:
            left_command = self.max_threshold

        if right_command < self.min_threshold:
            right_command = 0
        elif right_command > self.max_threshold:
            right_command = self.max_threshold

        return left_command, right_command

