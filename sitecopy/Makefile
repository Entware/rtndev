#
# Copyright (C) 2013-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2008

include $(TOPDIR)/rules.mk

PKG_NAME:=sitecopy
PKG_VERSION:=0.16.6
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://www.manyfish.co.uk/$(PKG_NAME)
PKG_HASH:=e06fdda007e54ddc6fae90a4e79768e5bfb7770c1139bcaac2e10d841d7458af

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/sitecopy
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Filesystem
	DEPENDS:=+libexpat +libneon
	TITLE:=WebDAV sync utility
	URL:=http://www.manyfish.co.uk/sitecopy/
	MAINTAINER:=Entware team, https://entware.net
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
