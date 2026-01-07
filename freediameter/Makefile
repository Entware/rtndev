#
# Copyright (C) 2020-2026 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=freediameter
PKG_VERSION:=1.6.0
PKG_REV:=5403feb543ed5e720165a4b3a3b4a365cdee28fb
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/freeDiameter/freeDiameter.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=10205d62e60a2d0ab0c75139c2339fb755d5969a5e77d89d227479a1c42228cb

PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk
include $(INCLUDE_DIR)/nls.mk

define Package/freediameter
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libgcrypt +libgnutls +libidn2
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
