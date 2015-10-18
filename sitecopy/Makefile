#
# Copyright (C) 2013 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=sitecopy
PKG_VERSION:=0.16.6
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://www.manyfish.co.uk/$(PKG_NAME)
PKG_MD5SUM:=b3aeb5a5f00af3db90b408e8c32a6c01

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/sitecopy
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Filesystem
	DEPENDS:=+libexpat +libneon
	TITLE:=WebDAV sync utility
	URL:=http://www.manyfish.co.uk/sitecopy/
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/sitecopy/description
 Sitecopy is for easily maintaining remote web sites. The program will upload
 files to the server which have changed locally, and delete files
 from the server which have been removed locally, to keep the remote site
 synchronized with the local site with a single command.
endef

define Package/sitecopy/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/sitecopy $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/share/sitecopy
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/share/sitecopy/{changes.awk,examplerc} $(1)/opt/share/sitecopy
endef

$(eval $(call BuildPackage,sitecopy))
