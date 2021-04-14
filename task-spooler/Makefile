#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=task-spooler
PKG_VERSION:=1.0.1
PKG_RELEASE:=1

PKG_SOURCE:=ts-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://viric.name/soft/ts
PKG_HASH:=f41ef307b0b9c7424398813b9c6e39d37a970831071e301842ba4b1145d56278

PKG_BUILD_DIR:=$(BUILD_DIR)/ts-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/task-spooler
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=task spooler
	URL:=http://tcforge.berlios.de/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/task-spooler/description
 Task spooler is a Unix batch system where the tasks spooled run one after
 the other. The amount of jobs to run at once can be set at any time. Each user
 in each system has his own job queue. The tasks are run in the correct context
 (that of enqueue) from any shell/process, and itask-spooler output/resultask-spooler can be easily
 watched.
endef

define Package/task-spooler/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/ts $(1)/opt/bin/tsp
endef

$(eval $(call BuildPackage,task-spooler))
