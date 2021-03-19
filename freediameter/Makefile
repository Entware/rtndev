#
# Copyright (C) 2020-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=freediameter
PKG_VERSION:=1.5.0
PKG_REV:=932fca1cbbe4
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=http://www.freediameter.net/hg/freeDiameter
PKG_SOURCE_PROTO:=hg
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=1425848bec5532f9ad60d1b9266a8e27c66745e91fcbc69fd62c6bf1c0eb4ecf

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/freediameter
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libgcrypt +libgnutls +libidn
	TITLE:=Diameter proto implementation
	URL:=http://www.freediameter.net
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/freediameter/description
 freeDiameter provides an extensible platform for deploying a Diameter network
 for your Authentication, Authorization and Accounting needs, whether you are
 involved in research or a network operator.
endef

CMAKE_OPTIONS += \
	-DDISABLE_SCTP=YES

define Build/InstallDev
	true
endef

define Package/freediameter/install
	$(INSTALL_DIR) $(1)/opt
	$(CP) $(PKG_INSTALL_DIR)/opt/{bin,lib} $(1)/opt
endef

$(eval $(call BuildPackage,freediameter))
