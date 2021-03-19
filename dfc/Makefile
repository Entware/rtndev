#
# Copyright (C) 2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=dfc
PKG_VERSION:=3.1.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://projects.gw-computing.net/attachments/download/615
PKG_HASH:=962466e77407dd5be715a41ffc50a54fce758a78831546f03a6bb282e8692e54

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/dfc
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	TITLE:=file system space usage information with style
	URL:=https://projects.gw-computing.net/projects/dfc
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/dfc/description
 dfc displays file system space usage using graphs and colors. In some ways,
 it is a modernized version of df as it is able to use colors, draw graphs and
 export its output to different formats such as CSV or HTML.
endef

CMAKE_OPTIONS += \
	-DNLS_ENABLED=false

define Package/dfc/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/dfc $(1)/opt/bin
endef

$(eval $(call BuildPackage,dfc))
