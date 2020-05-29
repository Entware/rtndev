#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2015, archieved

include $(TOPDIR)/rules.mk

PKG_NAME:=afpfs-ng
PKG_VERSION:=0.8.2
PKG_REV:=f6e24eb73c9283732c3b5d9cb101a1e2e4fade3e
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/simonvetter/afpfs-ng.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/afpfs-ng
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Filesystem
	DEPENDS:=+libfuse +libgcrypt +libgmp +libreadline
	TITLE:=a client for Apple Filing Protocol
	URL:=https://github.com/simonvetter/afpfs-ng
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/afpfs-ng/description
 afpfs-ng is an Apple Filing Protocol client that will allow BSD, Linux
 and Mac OS X systems to access files exported from a Mac OS system with
 AFP over TCP.
endef

define Build/Configure
	touch $(PKG_BUILD_DIR)/README
	touch $(PKG_BUILD_DIR)/lib/identify.c
	$(call Build/Configure/Default)
endef

define Package/afpfs-ng/install
	$(INSTALL_DIR) $(1)/opt
	$(CP) $(PKG_INSTALL_DIR)/opt/bin $(1)/opt
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libafpclient.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,afpfs-ng))
