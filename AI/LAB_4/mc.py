from search import Problem


def is_valid(state):
    misionariStanga, canibaliStanga, om, misionariDreapta, canibaliDreapta = state

    if(misionariStanga < canibaliStanga and om == "DREAPTA") or (misionariDreapta < canibaliDreapta and om == "STANGA")\
            or (misionariStanga > 3 or misionariDreapta > 3 or canibaliDreapta > 3 or canibaliStanga > 3):
        return False
    return True


class MC(Problem):
    def result(self, state, action):
        """The result of going to a neighbor is just that neighbor."""
        return action

    def value(self, state):
        pass

    def __init__(self, initial, goal):
        self.goal = goal
        self.initial = initial
        self.visited_states = []
        Problem.__init__(self, self.initial, self.goal)

    def __repr__(self):
        return "< State (%s, %s) >" % (self.initial, self.goal)

    def goal_test(self, state):
        return state == self.goal

    def actions(self, cur_state):
        actions = []

        self.visited_states.append(cur_state)
        if cur_state[2] == 'STANGA':

            # Duce unul din fiecare
            new_state = (cur_state[0] - 1, cur_state[1] - 1, 'DREAPTA', cur_state[3] + 1, cur_state[4] + 1)
            if is_valid(new_state):
                actions.append(new_state)

            # Duce un misionar
            new_state = (cur_state[0] - 1, cur_state[1], 'DREAPTA', cur_state[3] + 1, cur_state[4])
            if is_valid(new_state):
                actions.append(new_state)

            # Duce un canibal
            new_state = (cur_state[0], cur_state[1] - 1, 'DREAPTA', cur_state[3], cur_state[4] + 1)
            if is_valid(new_state):
                actions.append(new_state)

        else:
            # Se intoarce cu un misionar
            new_state = (cur_state[0] + 1, cur_state[1], 'STANGA', cur_state[3] - 1, cur_state[4])
            if is_valid(new_state):
                actions.append(new_state)

            # Se intoarce un canibal
            new_state = (cur_state[0], cur_state[1] + 1, 'STANGA', cur_state[3], cur_state[4] - 1)
            if is_valid(new_state):
                actions.append(new_state)

            # Se intoarce gol
            new_state = (cur_state[0], cur_state[1], 'STANGA', cur_state[3], cur_state[4])
            if is_valid(new_state):
                actions.append(new_state)

        return actions
