"""
Analyzing this later
"""
def visiblePoints(self, points: List[List[int]], angle: int, location: List[int]) -> int:
    if not points:
        return 0
    
    angle = math.radians(angle)
    angles = []
    on_location = 0
    
    for point in points:
        if point == location:
            on_location += 1
        else:
            angles.append(math.atan2(location[0] - point[0], location[1] - point[1]))
    
    angles.sort()
    angles += [2 * math.pi + x for x in angles]
    start = 0
    count = 0
    
    for end in range(len(angles)):
        start_angle = angles[end] - angle
        while angles[start] < start_angle:
            start += 1
        count = max(count, end - start + 1)
        
    return count + on_location