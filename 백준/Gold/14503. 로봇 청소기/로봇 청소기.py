import sys
input = sys.stdin.readline
DIR = [(0, -1), (1, 0), (0, 1), (-1, 0)] # 북 동 남 서

def main():
    n, m = map(int, input().split())
    y, x, d = map(int, input().split())
    room = [list(map(int, input().split())) for _ in range(n)]
    rotate_flag = False
    cleanup_cnt = 0
    # 1 - 벽 / 0 - 청소 X / -1 - 청소 O
    while 1:
        # 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소
        if not room[y][x]:
            room[y][x] = -1
            cleanup_cnt += 1
        # 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는지 확인
        for dx, dy in DIR:
            nx, ny = dx + x, dy + y
            if 0 <= nx < m and 0 <= ny < n and not room[ny][nx]:
                rotate_flag = True
                break
        # 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있다면, 반시계 방향으로 90도 회전
        if rotate_flag:
            rotate_flag = False
            d = (d + 3) % 4
            # 바라보고 있는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한칸 전진 후 1번으로 돌아간다.
            dx, dy = DIR[d]
            nx, ny = dx + x, dy + y
            if 0 <= nx < m and 0 <= ny < n and not room[ny][nx]:
                x, y = nx, ny
                continue
        # 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없다면, 후진
        else:
            td = (d + 2) % 4
            dx, dy = DIR[td]
            nx, ny = dx + x, dy + y
            # 후진하거나, 할 수 없다면 작동 정지
            if 0 <= nx < m and 0 <= ny < n and (room[ny][nx] == 0 or room[ny][nx] == -1):
                x, y = nx, ny
                continue
            else:
                break

    print(cleanup_cnt)
if __name__ == "__main__":
    main()