#!/usr/bin/python
# -*- coding: utf-8 -*-
import pygame
from pygame.locals import *
import sys
import random, string
import time
import locale
locale.setlocale(locale.LC_TIME, "tr_TR.UTF8")
import urllib2
import numpy as np
import os

import paho.mqtt.client as mqtt

ARKA_PLAN=(0,0,0)
display_width=1920
display_height=1080
basla=0
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe("quit")
    client.subscribe("mesaj")
    client.subscribe("hava")
    client.subscribe("lamba")

def on_message(client, userdata, msg):
    global basla,mesaj,mesaj_rect,img1
    #print(msg.topic+" "+str(msg.payload))

    if (msg.topic=="quit" and basla==1):
	pygame.quit()
    now=time.strftime("%M:%S")
                
    screen.fill(ARKA_PLAN)
    pygame.draw.rect(screen, (0,0,255), (10, 10, 1900, 120))
    screen.blit(baslik,baslik_rect)

    if (msg.topic=="mesaj"):
        mesaj=font48.render(unicode(str(msg.payload),"UTF8"), True, (255, 255, 255))
        mesaj_rect = mesaj.get_rect()
        mesaj_rect.center = ((display_width/2),160)

    if (msg.topic=="hava" ):
       f = open('/tmp/output.png', 'w')
       f.write(msg.payload)
       f.close()
       if (os.stat('/tmp/output.png').st_size>500):
           img1 = pygame.image.load('/tmp/output.png').convert()
    
    screen.blit(mesaj,mesaj_rect)
    screen.blit(img1,(800,450))
       	

    pygame.display.flip()
    basla=1
    pygame.time.wait(100)
    clock.tick(60)

client = mqtt.Client()
#client.username_pw_set("user", "pass")

client.on_connect = on_connect
client.on_message = on_message

client.connect("iot.eclipse.org", 1883, 60)
#client.connect("broker.mqttdashboard.com", 1883,60)




pygame.init()
screen=pygame.display.set_mode((display_width,display_height), FULLSCREEN)
clock = pygame.time.Clock()

img1 = pygame.image.load('./empty.png').convert()

pygame.mouse.set_visible(False)

font = pygame.font.SysFont("", 72)
font24 = pygame.font.Font(None, 24)
font36 = pygame.font.Font(None, 36)
font48 = pygame.font.Font(None, 48)
font76 = pygame.font.Font(None, 76)

baslik=font76.render(unicode('Nesnelerin İnterneti Kursu - Gösterge Paneli',"UTF8"), True, (255, 255, 255))

baslik_rect = baslik.get_rect()
baslik_rect.center = ((display_width/2),60)


mesaj=font48.render(unicode(str(""),"UTF8"), True, (255, 255, 255))
mesaj_rect = mesaj.get_rect()
mesaj_rect.center = ((display_width/2),160)

tarih=font48.render(unicode(time.strftime("%d %B %Y"),"UTF8"), 1, (255, 255, 255))

img1 = pygame.image.load('ab.png').convert()
    
client.loop_forever()

print "Burdayim"

