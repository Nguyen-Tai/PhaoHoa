class Global:
    winCanvas = None

    WindowWidth = 700
    WindowHeight = 500

    ListColors = [
        'snow', 'ghost white', 'white smoke', 'gainsboro', 'floral white', 'old lace',
        'linen', 'antique white', 'papaya whip', 'blanched almond', 'bisque', 'peach puff',
        'navajo white', 'lemon chiffon', 'mint cream', 'azure', 'alice blue', 'lavender',
        'lavender blush', 'misty rose',
        'pale green', 'spring green', 'lawn green', 'medium spring green', 'green yellow',
        'light yellow', 'yellow', 'gold',
        'PaleTurquoise1', 'PaleTurquoise2', 'PaleTurquoise3',
        'khaki1', 'khaki2', 'orchid1', 'orchid2', 'plum1', 'plum2'
    ]


    @staticmethod
    def CreateHat(toado, mausac):
        return Global.winCanvas.create_rectangle(
            toado.x - 1.5, toado.y - 1.5,
            toado.x + 1.5, toado.y + 1.5,
            fill=mausac)

