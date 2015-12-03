#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2009

include $(TOPDIR)/rules.mk

PKG_NAME:=vitetris
PKG_VERSION:=0.57
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://www.victornils.net/tetris
PKG_MD5SUM:=07d02ee03e2edd66a8741729e237f21f

include $(INCLUDE_DIR)/package.mk

define Package/vitetris
	SECTION:=games
	CATEGORY:=Games
	DEPENDS:=+libncurses
	TITLE:=Terminal-based Tetris clone
	URL:=http://www.victornils.net/tetris
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/vitetris/description
 Vitetris is a terminal-based Tetris clone by Victor Nilsson. Gameplay is
 much like the early Tetris games by Nintendo. Features include:
 configurable keys, highscore table, two-player mode with garbage,
 network play.
endef

define Build/Configure
	cd $(PKG_BUILD_DIR); \
	CC="$(TARGET_CC)" \
	CFLAGS="$(TARGET_CFLAGS)" \
	CPPFLAGS="$(TARGET_CPPFLAGS)" \
	LDFLAGS="$(TARGET_LDFLAGS)" \
	./configure \
		--prefix=$(PKG_INSTALL_DIR) \
		--without-joystick \
		--without-xlib \
		--with-curses
endef

define Package/vitetris/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/tetris $(1)/opt/bin/vitetris
	$(INSTALL_DIR) $(1)/opt/var
endef

$(eval $(call BuildPackage,vitetris))
