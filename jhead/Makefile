#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=jhead
PKG_VERSION:=3.08
PKG_REV:=4d04ac965632e35a65709c7f92a857a749e71811
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/Matthias-Wandel/jhead.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=9ba31c7a729e7f35d438024399c3c801c5db27a2cf760e126e04571d09ae579d

include $(INCLUDE_DIR)/package.mk

define Package/jhead
	SECTION:=multimedia
	CATEGORY:=Multimedia
	TITLE:=Exif Jpeg header manipulation tool
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/jhead/description
 Exif Jpeg header manipulation tool.
endef

define Package/jhead/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/jhead $(1)/opt/bin
endef

$(eval $(call BuildPackage,jhead))
