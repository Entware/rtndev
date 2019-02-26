#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=jhead
PKG_VERSION:=3.02
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://www.sentex.net/%7Emwandel/jhead
PKG_HASH:=85c9737c3dcc84b440a67307de9f76cbee7610697bfaf4877dd46afd71c7ed2a

include $(INCLUDE_DIR)/package.mk

define Package/jhead
	SECTION:=multimedia
	CATEGORY:=Multimedia
	TITLE:=Exif Jpeg header manipulation tool
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/jhead/description
 Exif Jpeg header manipulation tool
endef

define Package/jhead/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/jhead $(1)/opt/bin
endef

$(eval $(call BuildPackage,jhead))
