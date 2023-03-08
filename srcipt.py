from serial import Serial
from threading import Thread
from time import sleep

# Objeto do tipo serial que vai lidar com a comunicação
serial_debug = Serial('COM6', 115200, timeout=0)


# Task responsável por observar quando há um retorno do componente
def serial_recv():
    while True:
        if serial_debug.in_waiting:
            print(serial_debug.readline().decode('UTF-8'))


# Task responsável por enviar strings para o componente a cada 3 segundos
def debug_send():
    debug_string = [b'abcdefghijklmnopqrstuvwxyz\nABCDEFGHIJKLMNOPQRSTUVWXYZ\n0123456789\n',
                    b'strtok\nneeds\nto\nbe\ncalled\nseveral\ntimes\nto\nsplit\na\nstring\n']
    while True:
        for debug in debug_string:
            serial_debug.write(debug)
            sleep(3)


# Main para chamada das funções
def main():
    # rcv_task = Thread(target=serial_recv, args=())
    # rcv_task.start()
    debug_send()


main()