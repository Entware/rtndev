#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2008

include $(TOPDIR)/rules.mk

PKG_NAME:=afpfs-ng
PKG_VERSION:=0.8.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=@SF/$(PKG_NAME)/$(PKG_NAME)/$(PKG_VERSION)
PKG_HASH:=688560de1cde57ab8d9e0ef7dc6436dbf0267fe8884f9014e50ff92b297b01a8

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/afpfs-ng
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Filesystem
	DEPENDS:=+libfuse +libgcrypt +libgmp +libncurses +libreadline
	TITLE:=a client for Apple Filing Protocol
	URL:=https://sites.google.com/site/alexthepuffin/home
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/afpfs-ng/description
 afpfs-ng is an Apple Filing Protocol client that will allow BSD, Linux
 and Mac OS X systems to access files exported from a Mac OS system with
 AFP over TCP.
endef

define Package/afpfs-ng/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/afp{cmd,fs,fsd,getstatus} \
	    $(PKG_INSTALL_DIR)/opt/bin/mount_afp \
	    $(1)/opt/bin/
	$(LN) -s /opt/bin/mount_afp $(1)/opt/bin/afp_client
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libafpclient.so* $(1)/opt/lib/
endef

$(eval $(call BuildPackage,afpfs-ng))
