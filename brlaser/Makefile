#
# Copyright (C) 2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=brlaser
PKG_VERSION:=6
PKG_REV:=23117fe9e0266396e4791cdae84d979928aed135
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/pdewacht/brlaser.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/brlaser
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Printing
	DEPENDS:=+cups
	TITLE:=Brother laser printer driver
	URL:=https://github.com/pdewacht/brlaser
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/brlaser/description
 Brlaser is a CUPS driver for Brother laser printers without PCL/PostScript
 language support.
endef

TARGET_CFLAGS += -I$(STAGING_DIR)/opt/include

define Package/brlaser/install
	$(INSTALL_DIR) $(1)/opt
	$(CP) $(PKG_INSTALL_DIR)/opt/{lib,share} $(1)/opt
endef

$(eval $(call BuildPackage,brlaser))
