#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# FUSE module is not working, https://github.com/MediaFire/mediafire-fuse/issues/36

include $(TOPDIR)/rules.mk

PKG_NAME:=mediafire-fuse
PKG_VERSION:=0.9-20160112
PKG_REV:=aa75530a305c48bdea18da2dc954caeac1cd2f13
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/MediaFire/mediafire-fuse
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/mediafire-fuse
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Filesystem
	DEPENDS:=+libcurl +libfuse +jansson
	TITLE:=mediafire account utilities
	URL:=https://github.com/TurboGit/mediafire-fuse
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/mediafire-fuse/description
 A simple shell for a mediafire account and fuse module that is able to mount
 the mediafire share locally.
endef

define Package/mediafire-fuse/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/mediafire-shell \
		$(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/lib/libmf{api,utils}.so \
		$(1)/opt/lib
endef

$(eval $(call BuildPackage,mediafire-fuse))
