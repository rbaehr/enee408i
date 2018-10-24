class LeftRightController:

    def __init__(self, reference, p, min_threshold=-50, max_threshold=50):
        self.reference = reference
        self.min_threshold = min_threshold
        self.max_threshold = max_threshold
	self.p = p


    def control(self, point):
        error = self.reference - point

        right_command = int(self.p*error)
        left_command = int(-1*self.p*error)

        if left_command < self.min_threshold:
            left_command = 0
        elif left_command > self.max_threshold:
            left_command = self.max_threshold

        if right_command < self.min_threshold:
            right_command = 0
        elif right_command > self.max_threshold:
            right_command = self.max_threshold

        return left_command, right_command

