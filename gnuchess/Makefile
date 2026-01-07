# PDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=gnuchess
PKG_VERSION:=6.3.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@GNU/chess
PKG_HASH:=0b37bec2098c2ad695b7443e5d7944dc6dc8284f8d01fcc30bdb94dd033ca23a

include $(INCLUDE_DIR)/package.mk

define Package/gnuchess
	SECTION:=games
	CATEGORY:=Games
	TITLE:=GNU Chess
	DEPENDS:=+libreadline +libncurses +libpthread +libstdcpp
	URL:=http://www.gnu.org/software/chess/chess.html
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/gnuchess/description
 GNU Chess lets most modern computers play a full game of chess.
 It has a plain terminal interface but supports visual interfaces such as XBoard.
endef

define Package/gnuchess/conffiles
/opt/share/gnuchess/gnuchess.ini
endef

TARGET_LDFLAGS += \
	-lpthread

define Package/gnuchess/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/gnuchess $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/share/gnuchess
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/src/smallbook.bin $(1)/opt/share/gnuchess
endef

$(eval $(call BuildPackage,gnuchess))
