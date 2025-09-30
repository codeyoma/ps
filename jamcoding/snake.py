import sys
import pygame
from random import randint
from pygame.locals import QUIT, KEYDOWN, K_LEFT, K_RIGHT, K_UP, K_DOWN, Rect


pygame.init()  # 파이게임 초기화

# 게임의 기본 설정
GAMESIZE = 600  # 게임의 가로세로 설정
GRID = 30  # 그리드의 길이 지정

pygame.display.set_caption("Snake Game")  # 게임 타이틀 지정
SURFACE = pygame.display.set_mode((GAMESIZE, GAMESIZE))
FPSCLOCK = pygame.time.Clock()

# 폰트 설정
SMALLFONT = pygame.font.Font(None, 30)  # 현재 점수 표시용
DESCFONT = pygame.font.Font(None, 50)  # 결과 점수 표시용
TITLEFONT = pygame.font.Font(None, 80)  # 게임오버 타이틀 표시용

(W, H) = (GAMESIZE//GRID, GAMESIZE//GRID)  # 그리드의 수
FOODS = []  # 음식


class Snake:
    """ Snake 객체 """
    def __init__(self, pos):
        self.bodies = [pos]  # 뱀의 초기 머리 위치를 지정한다.
    def move(self, key):
        """Snake 를 프레임만큼 이동 """
        xpos, ypos = self.bodies[0]  # 머리 위치를 불러온다.
        if key == K_LEFT:  # 좌
            xpos -= 1
        elif key == K_RIGHT:  # 우
            xpos += 1
        elif key == K_UP:  # 상
            ypos -= 1
        elif key == K_DOWN:  # 하
            ypos += 1
        head = (xpos, ypos)  # 머리 위치를 업데이트한다.
        # 게임 오버 체크
        # 머리가 몸에 부딪치거나
        # 머리가 바깥으로 나간다면
        is_game_over = head in self.bodies or \
            not(0 <= xpos < W) or \
            not(0 <= ypos < H)
        self.bodies.insert(0, head)  # 업데이트 된 머리를 몸 위에 둔다.

        if head in FOODS:  # 머리가 먹이 좌표 위에 있다면(머리가 먹이를 먹었다면)
            # 먹이를 다른 장소로 이동
            i = FOODS.index(head)
            del FOODS[i]  # 먹혀진 먹이는 사라짐
            add_food(self)  # 먹이 추가
        else:
            # 먹이를 먹지 않았으므로 길어지지 않기 위해 꼬리를 지운다.
            self.bodies.pop()
        return is_game_over  # 게임오버 여부를 리턴한다.

    def draw(self):
        """Snake를 그린다."""
        for body in self.bodies:
            x, y = body
            # 좌표상 x * GRID, y * GRID위치에 배치된다.
            pygame.draw.rect(SURFACE, (0, 255, 255), (x * GRID, y * GRID, GRID, GRID))
            
def add_food(snake):
    """임의의 장소에 먹이를 배치"""
    while True:
        pos = (randint(0, W-1), randint(0, H-1))  # 랜덤으로 위치 지정
        if pos in FOODS or pos in snake.bodies:  # 만약 이미 있는 위치거나, 뱀의 몸이 있다면
            continue  # 다시 실행
        FOODS.append(pos)  # 해당 좌표에 먹이 추가
        break  # 먹이 추가 종료


def paint(snake, texts, message, score):
    """ 화면 전체 그리기 """
    SURFACE.fill((0, 0, 0))  # 화면을 검은색으로 채우기
    for food in FOODS:  # 먹이 그리기
        fx, fy = food
        # 먹이는 원으로 그린다.
        pygame.draw.ellipse(SURFACE, (0, 255, 0),
                            (fx * GRID, fy * GRID, GRID, GRID))

    snake.draw()  # 뱀 그리기

    for index in range(1, W):
        line_pos = index * GRID
        pygame.draw.line(SURFACE, (64, 64, 64),
                         (line_pos, 0), (line_pos, GAMESIZE))  # 세로선을 긋는다.(x축 고정, y축 이동)
        pygame.draw.line(SURFACE, (64, 64, 64),
                         (0, line_pos), (GAMESIZE, line_pos))  # 가로선을 긋는다.(x축 이동, y축 고정)

    if message != None and score != None:  # 게임 오버되면 message와 score가 지정되었을 것이므로
        message_pos = message.get_rect()  # 메세지의 위치 지정용
        score_pos = score.get_rect()  # 점수의 위치 지정용

        # 메세지의 위치를 맨 가운데로 지정
        message_pos.centerx = GAMESIZE//2
        message_pos.centery = GAMESIZE//2

        # 점수의 위치를 메세지의 아래로 지정
        score_pos.centerx = GAMESIZE//2
        score_pos.top = message_pos.bottom  # 점수의 상단을 메세지의 하단으로

        SURFACE.blit(message, message_pos)  # 게임 오버 메세지
        SURFACE.blit(score, score_pos)  # 결과 점수

    SURFACE.blit(texts, (50, 50))  # 현재 게임 점수 (좌측 상단에 표시)
    pygame.display.update()  # 게임 업데이트

def main():
    """ 메인 루틴"""

    # 기본 변수 초기화
    key = K_DOWN  # 아무 키도 입력이 없을 때 지정할 키
    message = None
    score = None
    game_over = False
    snake = Snake((int(W/2), int(H/2)))  # 뱀의 위치를 맨 가운데로

    for i in range(5):  # 미리 먹이 5개 로드
        add_food(snake)

    while True:
        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == KEYDOWN:
                key = event.key  # 입력된 키 받아옴

        if game_over:  # 만약 게임오버되었다면
            message = TITLEFONT.render("Game Over!", True, (255, 255, 0))
            score = DESCFONT.render(f"Score: {len(snake.bodies)-1}", True, (255, 0, 0))  # 머리를 제외한 점수
        else:
            game_over = snake.move(key)  # move하면서 게임오버 여부 가져옴
        texts = SMALLFONT.render(f"Score: {len(snake.bodies)-1}", True, (255, 0, 255))
        paint(snake, texts, message, score)  # 화면 업데이트

        FPSCLOCK.tick(5)  # 숫자를 바꿔서 속도 조절 (5는 초당 5프레임)


if __name__ == '__main__':
    main()
