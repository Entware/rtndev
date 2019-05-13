#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=axel
PKG_VERSION:=2.17.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://github.com/axel-download-accelerator/axel/releases/download/v$(PKG_VERSION)
PKG_HASH:=f86cbc43b5bd6e6ee543566b232f651d2e15a7caf822d7708e9869dc1f5840b4

include $(INCLUDE_DIR)/package.mk

define Package/axel
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=File Transfer
	DEPENDS:=+libopenssl
	TITLE:=axel download accelerator
	URL:=https://github.com/axel-download-accelerator/axel
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/axel/description
 Description: light command line download accelerator
 Axel tries to accelerate the downloading process by using multiple
 connections for one file, similar to DownThemAll and other famous
 programs. It can also use multiple mirrors for one download.
 Using Axel, you will get files faster from Internet. So, Axel can
 speed up a download up to 60% (approximately, according to some tests).
 Axel supports HTTP, HTTPS, FTP and FTPS protocols.
 Axel tries to be as light as possible, so it might be useful as a
 wget clone (and other console based programs) on byte-critical systems. 
endef

define Package/axel/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/axel $(1)/opt/bin
endef

$(eval $(call BuildPackage,axel))
